import re
input()
print(re.sub(r'(?<=[aeiouy])[aeiouy]+', '', input()))