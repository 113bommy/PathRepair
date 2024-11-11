import re
input()
print(re.sub('(?<=[aeiouy])[aeiouy]+', '', input()))