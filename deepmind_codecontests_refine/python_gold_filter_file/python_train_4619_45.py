n = int(input())
count=0
for i in range(n):
    n=input()
    if n.count('1')>=2:
        count+=1
print(count)