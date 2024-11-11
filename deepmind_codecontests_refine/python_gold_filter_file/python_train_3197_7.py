n = int(input())
s = input()
print('No'if s == '0' or '000' in s or s[0] == '0' and s[1] == '0' or s[-1] == '0' and s[-2] == '0' or '11' in s else 'Yes')