n=int(input())
count=0
for c in range(n):
    k=input()
    if k.count('1') >= 2:
        count+=1

print(count)