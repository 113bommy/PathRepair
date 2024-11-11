_, s = input(), input().strip()
print("Yes" if ('??' in s or 'C?C' in s or 'M?M' in s or 'Y?Y' in s or 
s[0] == '?' or s[-1] == '?') and not ('CC' in s or 'MM' in s or 'YY' in s) else "No")