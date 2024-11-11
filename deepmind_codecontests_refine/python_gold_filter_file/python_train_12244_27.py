n, k = map(int, input().split())
s = input()
print(['YES', 'NO'][s.count(max(set(s), key=s.count)) > k])
