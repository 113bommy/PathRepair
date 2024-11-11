n=int(input())
print(n*n//2+n*n%2)
for i in range(n):
    if i %2==1:
        print('.C'*(n//2)+'.'*(n%2))
    else:
        print('C.'*(n//2)+'C'*(n%2))