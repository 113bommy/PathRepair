N = int(input())
A = list(map(int, input().split()))


def check(k):
    if k == 1:
        for i in range(1, N):
            if A[i - 1] >= A[i]:
                return False
        return True
    stack = []
    for i in range(1, N):
        if A[i - 1] >= A[i]:
            q = A[i]
            while True:
                if stack:
                    if stack[-1][0] > q:
                        stack.pop()
                    else:
                        break
                else:
                    break

            p = q
            while p >= 1:
                if not stack:
                    stack.append([p, 1])
                    break
                if stack[-1][0] == p:
                    if stack[-1][1] == k - 1:
                        if p != 1:
                            stack.pop()
                            p -= 1
                        else:
                            return False
                    else:
                        stack[-1][1] += 1
                        break
                else:
                    stack.append([p, 1])
                    break
    return True


l, r = 0, N
while r - l > 1:
    mid = (l + r) // 2
    if check(mid):
        r = mid
    else:
        l = mid

print(r)