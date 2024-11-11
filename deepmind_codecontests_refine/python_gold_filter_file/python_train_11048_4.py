n=int(input())
s1,s2=0,0
for i in range(2*n):
    x,y=map(int,input().split())
    s1+=x
    s2+=y

print(int(s1/n),int(s2/n))