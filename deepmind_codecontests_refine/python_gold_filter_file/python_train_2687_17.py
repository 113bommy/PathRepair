import re
print(len(max(re.findall('[ACGT]*',input()), key=len)))