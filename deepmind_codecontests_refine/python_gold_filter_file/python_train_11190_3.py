__author__ = 'victormion'

# For more information visit page http://codeforces.com/blog/entry/18696#comment-237290

w, m = input().strip().split()
w = int(w)
m = int(m)
def solve(w, m):
    return  w <= 3 or m == 1 or trySolve(w, m-1) or trySolve(w,m) or trySolve(w, m+1)

def trySolve(w,  m):
    return m%w == 0 and solve(w, m//w)

if solve(w,m):
    print("YES")
else:
    print("NO")