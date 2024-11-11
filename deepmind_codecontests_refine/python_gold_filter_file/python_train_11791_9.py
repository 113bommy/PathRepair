# Codeforces Subsequences
def isvalid(arr,n):
    r = 1 
    for i in range(10):
        r = r * arr[i]
        if r >= n :
            return True 
    return False 

def solve(n) :
    arr=[1]*10
    if isvalid(arr,n):
        return arr
    last = 0 
    while True :
        arr[last] = arr[last] + 1 
        if isvalid(arr,n) :
            return arr
        last = last + 1 
        if last == 10 :
            last = 0
def solution(n):
    arr = solve(n)
    ans = ''
    st = 'codeforces'
    for i in range(len(arr)) :
        ans = ans + st[i]*arr[i]
    return ans 
    
n = int(input())
op = solution(n)
print(op)