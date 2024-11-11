s = input()
K = int(input())
substrings = {s[i:j]:0 for i in range(len(s)) for j in range(i+1, min(i+1+K, len(s)+1))}
print(sorted(substrings)[K-1])
