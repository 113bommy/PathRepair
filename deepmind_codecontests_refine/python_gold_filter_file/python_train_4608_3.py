s=[]
for iii in range(int(input())):
    v,c,t1,t2=map(int,input().split())
    if t2>min(v,c):
        s.append('no')
        continue
    if c<=v:
        c-=t2
    else:
        v-=t2
    if t1<=v+c:
        s.append('yes')
    else:
        s.append('no')
for i in s:
    print(i)
