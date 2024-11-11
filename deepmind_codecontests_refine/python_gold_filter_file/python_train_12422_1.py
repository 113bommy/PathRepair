"""
Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
"""

if __name__ == "__main__":
    # Write your solution here
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        if n == 0 or n == 1:
            print(0)
        else:
            ans = 0
            arr.sort()
            # for i in range(n-2):
            #     for j in range(i+2, n):
            #         ans += arr[j] - arr[i]
            prefix = [0]
            for i in range(1, n):
                ele = arr[i] + prefix[-1]
                prefix.append(ele)
            # print(prefix)
            for i in range(2, n):
                ans += (arr[i]*(i-1) - prefix[i-2])
            print(-ans)


