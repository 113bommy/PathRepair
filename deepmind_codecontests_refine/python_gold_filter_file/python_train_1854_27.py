x = input()
for i in range(3):
  if x[i]==x[i+1]:
    print('Bad')
    exit()
print('Good')