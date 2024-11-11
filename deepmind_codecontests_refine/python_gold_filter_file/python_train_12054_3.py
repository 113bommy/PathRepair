s=int(input())
k=0
for x in range(s+1):
    if x%3!=0 and x%5!=0:
        k+=x
print(k)