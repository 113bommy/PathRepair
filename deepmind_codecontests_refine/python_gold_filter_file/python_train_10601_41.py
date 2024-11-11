A,B=map(int,input().split())
cnt=0
while A<=B:
    A*=2
    cnt+=1
print(cnt)