n=int(input())
print(n//2)
print('2 '*((n//2)-(n%2)),end='')
print('3'*(n%2))