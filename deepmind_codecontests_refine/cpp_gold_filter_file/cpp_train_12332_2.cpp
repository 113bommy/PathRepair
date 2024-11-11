#include <bits/stdc++.h>
int main() {
  int Ns, Nm, Nl, Nxl, Nxxl, N;
  char Tam[5];
  scanf("%d %d %d %d %d\n", &Ns, &Nm, &Nl, &Nxl, &Nxxl);
  scanf("%d\n", &N);
  while (N--) {
    scanf("%s\n", &Tam);
    if (strcmp(Tam, "S") == 0) {
      if (Ns != 0) {
        printf("S\n");
        Ns--;
      } else if (Nm != 0) {
        printf("M\n");
        Nm--;
      } else if (Nl != 0) {
        printf("L\n");
        Nl--;
      } else if (Nxl != 0) {
        printf("XL\n");
        Nxl--;
      } else if (Nxxl != 0) {
        printf("XXL\n");
        Nxxl--;
      }
    } else if (strcmp(Tam, "M") == 0) {
      if (Nm != 0) {
        printf("M\n");
        Nm--;
      } else if (Nl != 0) {
        printf("L\n");
        Nl--;
      } else if (Ns != 0) {
        printf("S\n");
        Ns--;
      } else if (Nxl != 0) {
        printf("XL\n");
        Nxl--;
      } else if (Nxxl != 0) {
        printf("XXL\n");
        Nxxl--;
      }
    } else if (strcmp(Tam, "L") == 0) {
      if (Nl != 0) {
        printf("L\n");
        Nl--;
      } else if (Nxl != 0) {
        printf("XL\n");
        Nxl--;
      } else if (Nm != 0) {
        printf("M\n");
        Nm--;
      } else if (Nxxl != 0) {
        printf("XXL\n");
        Nxxl--;
      } else if (Ns != 0) {
        printf("S\n");
        Ns--;
      }
    } else if (strcmp(Tam, "XL") == 0) {
      if (Nxl != 0) {
        printf("XL\n");
        Nxl--;
      } else if (Nxxl != 0) {
        printf("XXL\n");
        Nxxl--;
      } else if (Nl != 0) {
        printf("L\n");
        Nl--;
      } else if (Nm != 0) {
        printf("M\n");
        Nm--;
      } else if (Ns != 0) {
        printf("S\n");
        Ns--;
      }
    } else if (strcmp(Tam, "XXL") == 0) {
      if (Nxxl != 0) {
        printf("XXL\n");
        Nxxl--;
      } else if (Nxl != 0) {
        printf("XL\n");
        Nxl--;
      } else if (Nl != 0) {
        printf("L\n");
        Nl--;
      } else if (Nm != 0) {
        printf("M\n");
        Nm--;
      } else if (Ns != 0) {
        printf("S\n");
        Ns--;
      }
    }
  }
  return 0;
}
