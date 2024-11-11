K=int(input())
A,B=map(int,input().split())

print('OK' if B-B%K>=A else 'NG')
