n=int(input())
p=input().split()

for j in range(n):
    if p[j]=='1':
        print('HARD')
        break
    else:
        if j==n-1:
            print('EASY')
