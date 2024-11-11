import re
print(max(map(len,re.split("[^ATCG]",input()))))