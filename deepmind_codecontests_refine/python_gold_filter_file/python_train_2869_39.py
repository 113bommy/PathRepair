def solution(s: str) -> str:
    if len(s) <= 10:
        return s
    return s[0] + f"{len(s) - 2}" + s[-1]

n = int(input())
words = []
for i in range(n):
    words.append(str(input()))
for i in range(n):
    print(solution(words[i]))
