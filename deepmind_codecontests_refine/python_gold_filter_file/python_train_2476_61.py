A,B,C,D = map(int,input().split())

if -(-C//B) > -(-A//D):
    print("No")
else:
    print("Yes")