n = int(input())
a_end_count = 0
b_start_count = 0
ab_count = 0
a_or_b_count = 0
for _ in range(n):
  s = input()
  if s[-1] == 'A':
    a_end_count += 1
  if s[0] == 'B':
    b_start_count += 1
  if s[-1] == 'A' or s[0] == 'B':
    a_or_b_count += 1
  ab_count += s.count('AB')
ab_count += max(0, min([a_or_b_count - 1, a_end_count, b_start_count]))
print(ab_count)