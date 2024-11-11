S = input()
for c in range(0, ord('z') - ord('a')+1):
    last_c = -1
    for i,s in enumerate(S):
        if ord(s) - ord('a') == c:
            if last_c == -1:
                last_c = i
                continue
            if i - last_c <= 2:
                print(last_c+1,i+1)
                exit()
            last_c = i
print(-1,-1)