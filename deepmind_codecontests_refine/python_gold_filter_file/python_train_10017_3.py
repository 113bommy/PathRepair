n = int(input())
arr = list(map(int, input().split(' ')))

def cookies(n, arr):
    odd = 0
    for i in arr:
        if(i % 2 == 1):
            odd += 1
    
    return odd if(odd % 2 == 1) else n - odd

print(cookies(n, arr))