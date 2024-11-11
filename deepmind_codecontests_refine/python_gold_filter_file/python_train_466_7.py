m=list(map(int,input().split()))
w=list(map(int,input().split()))
h1,h2=map(int,input().split())
s=0
for i in range(5):
    s=s+max(0.3*(500*(i+1)),(1-(m[i]/250))*(500*(i+1))-50*w[i])
s=s+100*h1-50*h2
print(int(s))