s = int(input())
count = 0
for i in range(s):
    a,b=input().split()
    if int(a)+2<=int(b):
        count+=1

print(count)