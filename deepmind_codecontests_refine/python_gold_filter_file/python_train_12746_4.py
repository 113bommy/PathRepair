name = input()

from math import floor, ceil

mirrored_letters = 'AHIMOTUVWXY'

mid = len(name) / 2
mid_b = floor(mid)
mid_a = ceil(mid)
before_mid_name = name[:mid_b]
if before_mid_name == name[mid_a:][::-1] and all([n in mirrored_letters for n in before_mid_name]) and name[mid_b] in mirrored_letters:
  print("YES")
else:
  print("NO")

