n = int(input())
def solve(n):
    for item in range(n//1234567 + 1):
        for i in range(n//123456 + 1):
            current = n - (item*1234567 + i*123456)
            if current < 0:
                break
            maxi = current // 1234 + 1

            low = 0
            hi = maxi
            mid = maxi//2
            while low < hi:
                if mid*1234 == current:
                    return "YES"
                elif mid*1234 < current:
                    low = mid+1
                else:
                    hi = mid - 1
                mid = low + (hi - low) // 2
    return "NO"
print(solve(n))
