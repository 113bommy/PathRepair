s = input()
print('Bad' if True in [s[i] is s[i + 1] for i in range(3)] else 'Good')
