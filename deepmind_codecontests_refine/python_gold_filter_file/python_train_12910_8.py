n,k = map(int,input().split())
w = [int(input()) for i in range(n)]

def binarySearch(left,right):
    mid = 0
    while right > left:
        mid = int(left + (right - left)//2)
        if check(mid,w,k):
            right = mid
        else:
            left = mid + 1
    return left

def check(p,w,k):
    k_tmp = 1
    w_tmp = 0
    for w_i in w:
        w_tmp += w_i
        if w_tmp > p:
            w_tmp = w_i
            k_tmp += 1
            if k_tmp > k:
                return False
    return True

print(binarySearch(max(w),sum(w)))