a,b = map(int,input().split())
count=0
while(b>=a):
    a=a*3
    b=b*2
    count+=1
print(count)