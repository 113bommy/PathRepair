n=int(input())
count=0
for i in range(n):
    a=input()
    if a.count('1')>=2:
        count+=1
print(count) 