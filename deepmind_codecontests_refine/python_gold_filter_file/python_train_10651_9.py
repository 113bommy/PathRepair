n=int(input())
all={}
p1,g1,t1=[],[],[]
for i in range(n):
    a,b=input().split()
    a=int(a)
    p,g,t=0,0,0
    for j in range(a):
        nu=input()
        if nu[0]==nu[1] and nu[1]==nu[3] and nu[3]==nu[4] and nu[4]==nu[6] and nu[6]==nu[7]:
            t+=1
        elif nu[0]>nu[1] and nu[1]>nu[3] and nu[3]>nu[4] and nu[4]>nu[6] and nu[6]>nu[7]:
            p+=1
        else:
            g+=1
    p1.append(p)
    g1.append(g)
    t1.append(t)
    all[b]={"p":p,"g":g,"t":t}
p,g,t=max(p1),max(g1),max(t1)
p1,g1,t1=[],[],[]
for i,j in all.items():
    if j["p"]==p:
        p1.append(i)
    if j["g"]==g:
        g1.append(i)
    if j["t"]==t:
        t1.append(i)
print("If you want to call a taxi, you should call:",", ".join(t1)+".")
print("If you want to order a pizza, you should call:",", ".join(p1)+".")
print("If you want to go to a cafe with a wonderful girl, you should call:",", ".join(g1)+".")