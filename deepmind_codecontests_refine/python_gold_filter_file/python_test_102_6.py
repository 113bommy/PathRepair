import sys, collections, math, bisect, heapq, random, functools

input = sys.stdin.readline
out = sys.stdout.flush


def solve():
    n,m = map(int,input().split())
    x,y = 1,1
    cx,cy = 1,1
    s = input().rstrip('\n')
    left,right,bottom,top = 0,0,0,0
    lp,rp,bp,tp = [0,0],[0,0],[0,0],[0,0]
    px,py = 0,0
    for i in range(len(s)):
        if s[i] == 'L':
            if cy - 1 <= 0:
                if y + 1 > m or y + right + 1 > m:
                    break
                else:

                    y += 1
                    py += 1
            else:
                cy -= 1
            if cy - y < left:
                left = cy - y
                lp = [cx,cy]

        elif s[i] == 'R':
            if cy + 1 > m:
                if y - 1 <= 0 or y - abs(left) - 1 <= 0:
                    break
                else:
                    y -= 1
                    py -= 1
            else:
                cy += 1
            if cy - y > right:
                right = cy - y
                rp = [cx,cy]


        elif s[i] == 'U':
            if cx - 1 <= 0:
                if x + 1 > n or x + bottom + 1 > n:
                    break
                else:
                    x += 1
                    px += 1
            else:
                cx -= 1
            if cx - x < top:
                top = cx - x
                tp = [cx,cy]


        else:
            if cx + 1 > n:
                if x - 1 <= 0 or x - abs(top) - 1 <= 0:
                    break
                else:
                    x -= 1
                    px -= 1

            else:
                cx += 1
            if cx - x > bottom:
                bottom = cx - x
                bp = [cx,cy]
    print(x,y)




if __name__ == '__main__':
    for i in range(int(input())):
        solve()