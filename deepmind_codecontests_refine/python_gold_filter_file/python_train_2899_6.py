S = input()
ans = min(max(map(len, S.split(c)))
          for c in [chr(i + 97) for i in range(26)]
          if c in S)
print(ans)