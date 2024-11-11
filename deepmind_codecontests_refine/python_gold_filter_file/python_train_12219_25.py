n= int(input())
l = list(map(int,input().split()))
ex=["chest","biceps","back"]
m=[0,0,0]

for i in range(len(l)):
    m[i%3]+=l[i]
print(ex[m.index(max(m))])
