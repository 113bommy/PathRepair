n,k=map(int,input().split())
s=input()
arr=[0 for i in range(26)]
if n==1 and k==1:
    print(1)
elif n==1 and k>1:
    print(0)
else:
    i = 0
    j = 1
    while j < n:
        if s[j] == s[j - 1]:
            if j == n - 1:
                val = ord(s[j]) - 97
                if j - i+1 >= k:
                    arr[val] += (j+1-i) // k
            j += 1
        else:
            val = ord(s[j - 1]) - 97
            if j - i >= k:
                arr[val] += (j - i) // k
            i = j
            j += 1

    print(max(arr))