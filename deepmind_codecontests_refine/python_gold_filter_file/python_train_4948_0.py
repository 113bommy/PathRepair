x=int(input())
if x==2:
    print("YES")
    quit()
y=list(map(int,input().split(' ')))
z=list(map(int,input().split(' ')))
kq=[i for i in y if i != 0]
jl=[i for i in z if i != 0]
o=[0]*200001
p=[0]*200001
t=[]
for i in range(len(kq)):
    o[kq[i]] = i+1
for i in range(len(jl)):
    p[jl[i]] = i+1
for i in range(1,x):
    t.append((p[i]-o[i])%(x-1))
if t.count(t[0])==len(t):
    print("YES")
else:
    print("NO")