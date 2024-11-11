length = int(input())
interview = input()
substring = 'ogo'+(length - 3)*'go'
while len(substring) > 2:
  if substring in interview:
    interview = interview.replace(substring, '***')
  substring = substring[:-2]
print(interview)