t = int(input())
for _ in range(t):
    s = input()
    ans = 0
    skip_to = None
    for i in range(len(s)):
        if skip_to and i < skip_to:
            continue
        if s[i] == "1":
            for j in range(i + 1, len(s)):
                if s[j] == "1":
                    ans += j - i - 1
                    skip_to = j
                    break
    print(ans)


        
