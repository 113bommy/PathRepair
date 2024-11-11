k, s = map(int, input().split())
result = [i_1+i_2 for i_1 in range(k+1) for i_2 in range(k+1) if 0<=s-i_1-i_2<=k]
print(len(result))