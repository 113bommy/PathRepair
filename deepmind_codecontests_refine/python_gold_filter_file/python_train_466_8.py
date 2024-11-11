m=[]
w=[]
h=[]
for a in input().split():
    m.append(int(a))
for a in input().split():
    w.append(int(a))
for a in input().split():
    h.append(int(a))
s=h[0]*100-h[1]*50
con=500
for i in range(5):
    s+=max(0.3*con*(i+1), (250-m[i])*con*(i+1)//250-50*w[i])
print(int(s))