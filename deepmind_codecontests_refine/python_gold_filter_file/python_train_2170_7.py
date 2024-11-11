N=int(input())
A=list(map(int,input().split()))
hiku=1
ans=1
for i in A:
        if i%2 == 0:hiku*=2
        ans*=3
print(ans-hiku)