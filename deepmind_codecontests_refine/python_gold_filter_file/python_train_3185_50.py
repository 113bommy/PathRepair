l,b=map(int,input().split())
count=0
while l<=b:
    l=l*3
    b=b*2
    count+=1
print(count)
