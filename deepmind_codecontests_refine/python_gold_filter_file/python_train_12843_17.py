_, k = map(int, input().split())
res = [1 for st in input().split() if st.count('4') + st.count('7') <= k]
print(sum(res))