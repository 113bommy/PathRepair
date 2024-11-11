T = int(input())
for _ in range(T):
    X, Y = map(int, input().split())
    A, B = map(int, input().split())
    cost = 0
    if(X==Y):
        cost+=min(B*(abs(X)), 2*A*(abs(X)))
    elif((Y>=0 and X>=0) or (X<=0 and Y<=0)):
        cost+=A*(abs(X-Y)) + min(B*(min(abs(X), abs(Y))), 2*A*(min(abs(X), abs(Y))))
    elif((X>=0 and Y<=0) or (X<=0 and Y>=0)):
        cost+=A*(abs(X)+abs(Y))
    print(cost)