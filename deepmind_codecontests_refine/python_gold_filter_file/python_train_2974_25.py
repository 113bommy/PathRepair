import re

interview = int(input())
speech = input()

speech = re.sub(r'ogo(go)*', '***', speech)
print(speech)

