n=int(input())
a=list(map(int,input().split()))
for i in a:
    if i%2!=0:
        print('First')
        exit(0)
print('Second')