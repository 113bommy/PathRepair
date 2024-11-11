s = input()
# 'a', 'e', 'i', 'o' or 'u', and even digit is one of '0', '2', '4', '6' or '8'.
print (len([c for c in s if c in 'aeiou13579']))