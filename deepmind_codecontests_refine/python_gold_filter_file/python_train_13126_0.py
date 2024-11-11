n=int(input())
l=list(map(int,input().split()))
a=list(map(int,input().split()))
if(sum(a)<=sum(l)):
    print('Yes')
else:
    print('No')
