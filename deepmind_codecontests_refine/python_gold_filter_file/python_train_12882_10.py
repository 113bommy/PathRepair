b = input()
b = set(map(int,input().split()))
if 0 in b:
    print(len(b)-1)
else:
    print(len(b))
