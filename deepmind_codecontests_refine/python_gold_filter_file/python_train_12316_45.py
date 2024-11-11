k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())
a = []
count=0
for i in range(1,d+1):
    a.append(i)
for i in a:
    if i%k==0:
        count+=1
    elif i%l==0:
        count+=1
    elif i%m==0:
        count+=1
    elif i%n==0:
        count+=1
print(count)