n=int(input())
li=list(map(int,input().split()))
li.sort()
print(li[n//2]-li[n//2-1])