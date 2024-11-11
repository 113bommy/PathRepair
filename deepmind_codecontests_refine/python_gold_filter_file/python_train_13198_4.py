def between(x, y1, y2):
    if x % 3 != 1:return False
    if y1 > y2:
        y1,y2= y2,y1
    for i in range(10):
        if y1 + i >= y2:break
        if (y1 + i) % 3 == 1:
            return True
    return False
    
def dist(x1, y1, x2, y2):
    three = 1
    extra = 0
    for i in range(33):
        if x1 // three == x2 // three and between(x1 //three, y1 //three, y2//three):
            extra = max(extra, min(min(x1 % three, x2 %three) + 1, three - max(x1 % three, x2 % three)))
        three *= 3

    return abs(x1-x2) + abs(y1-y2) + extra * 2

def solve():
    a,b,c,d = map(int, input().split())
    a,b,c,d = a-1,b-1,c-1,d-1
    print(max(dist(a,b,c,d), dist(b,a,d,c)))

q = int(input())
for _ in range(q):
    solve()