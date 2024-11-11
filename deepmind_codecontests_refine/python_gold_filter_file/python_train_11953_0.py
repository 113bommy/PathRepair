n = int(input())
a,b,c = input(),input(),input()

count = 0
for i in range(n):
    count += len(set([a[i],b[i],c[i]]))-1
print(count)