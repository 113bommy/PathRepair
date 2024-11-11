n, k = map(int, input().split())
s = input() + '#'
let = [0] * 26

cnt = 1
for i in range(1, n + 1):
    if s[i] == s[i - 1]:
        cnt += 1
    else:
        let[ord(s[i - 1]) - ord('a')] += cnt // k
        cnt = 1
        
print(max(let))