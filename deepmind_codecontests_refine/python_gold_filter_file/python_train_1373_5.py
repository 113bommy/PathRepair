
w = list(map(int,input().split()))
b1 = list(map(int,input().split()))
b2 = list(map(int,input().split()))

def inside(x,y,rect):
    return rect[0] <= x and x <= rect[2] and rect[1] <= y and y <= rect[3]

b1_cover = [inside(w[0],w[1],b1), inside(w[0],w[3],b1),
            inside(w[2],w[3],b1), inside(w[2],w[1],b1)]
b2_cover = [inside(w[0],w[1],b2), inside(w[0],w[3],b2),
            inside(w[2],w[3],b2), inside(w[2],w[1],b2)]

if any(not(b1_cover[i] or b2_cover[i]) for i in range(4)):
    print('YES')
    exit(0)

if not all(b1_cover) and not all(b2_cover):
    if b1[2] < b2[0] or b2[2] < b1[0] or b1[3] < b2[1] or b2[3] < b1[1]:
        print('Yes')
        exit(0)
print('NO')

